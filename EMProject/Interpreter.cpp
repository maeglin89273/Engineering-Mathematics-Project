#include "Interpreter.h"
#include "RegistrationArea.h"
using namespace em::intrprt;


Interpreter::Interpreter(array<PatternAnalyzer^>^ patternList) {

	this->needNext = nullptr;
	this->beenIntrprtedLineCount = 0;
	this->fullLine = gcnew StringBuilder(50);
	this->pTable = gcnew PatternTable(patternList);
	this->proxyVTable = gcnew VariableTableProxy();
	this->engine = gcnew ArithmeticEngine(this->variableTable);
}

Message^ Interpreter::interpret(String^ line, int% beenIntrprtedLineCount) {
	
	beenIntrprtedLineCount = this->beenIntrprtedLineCount;
	this->beenIntrprtedLineCount = 0;

	Match^ result = this->commentPattern->Match(line);
	if (result->Success) {
		if (String::IsNullOrWhiteSpace(result->Groups[1]->Value)) {
			if (beenIntrprtedLineCount > 0) {
				this->beenIntrprtedLineCount = beenIntrprtedLineCount + 1;
			}

			return Message::PASS_NO_CONTENT_MSG;
		}
		line = result->Groups[1]->Value;
	}

	
	line = line->Trim();
	if (this->needNext != nullptr) {
		Match^ match = this->needNext->bindingPattern->Match(line);
		if (match->Success) {
			return this->needNext->analyze(match, this);
		}

		this->releaseNextLine();
	} else {

		if (line->EndsWith("\\")) {
			fullLine->Append(line->Substring(0, line->Length - 1));
			this->beenIntrprtedLineCount = beenIntrprtedLineCount + 1;
			return Message::PASS_NO_CONTENT_MSG;
		} else {
			fullLine->Append(line);
			PatternAnalyzer^ analyzer = this->pTable->matchPattern(fullLine->ToString(), result);
			fullLine->Clear();
			if (analyzer != nullptr) {
				return analyzer->analyze(result, this);
			}
		}
	}

	return Message::SYNTAX_ERROR_MSG;
}

Interpreter::~Interpreter() {

	delete this->needNext;
	delete this->pTable;
	delete this->proxyVTable;
}

void Interpreter::releaseNextLine() {
	//cannot delete it, because "it" invoke this method
	this->needNext = nullptr;
}

void Interpreter::needNextLine(PatternAnalyzer^ tmpAnalyzer) {
	this->needNext = tmpAnalyzer;
}

Interpreter::VariableTableProxy::VariableTableProxy() {
}

Interpreter::VariableTableProxy::~VariableTableProxy() {
}

bool Interpreter::VariableTableProxy::contains(String^ name) {
	return allVTable->contains(name);
}

bool Interpreter::VariableTableProxy::addVariable(String^ name, MathObject^ mo) {

	if (this->allVTable->addVariable(name, mo)) {

		this->VariableTable::addVariable(name, mo);
		return true;
	}

	return false;
}

bool Interpreter::VariableTableProxy::deleteVariable(String^ name) {

	if (this->allVTable->deleteVariable(name)) {

		this->VariableTable::deleteVariable(name);
		return true;
	}

	return false;
}

void Interpreter::VariableTableProxy::load(VariableTable^ vTable) {

	if (vTable == nullptr) {

		this->allVTable->load(this);
	} else {

		this->allVTable->load(vTable);
		this->VariableTable::load(vTable);
	}
	
}

void Interpreter::VariableTableProxy::unload(VariableTable^ vTable) {

	if (vTable == nullptr) {

		this->allVTable->unload(this);
		this->clear();
	} else {

		this->allVTable->unload(vTable);
		this->VariableTable::unload(vTable);
	}
}

bool Interpreter::VariableTableProxy::checkGet(String^ name, MathObject^% mo) {
	return this->allVTable->checkGet(name, mo);
}

System::Collections::Generic::IEnumerator<KeyValuePair<String^, MathObject^>>^ Interpreter::VariableTableProxy::GetEnumerator() {
	return this->allVTable->GetEnumerator();
}