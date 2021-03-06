#include "Message.h"
#include "KeywordCollection.h"

using namespace em::intrprt;
using System::Text::StringBuilder;

Message::Message(State t, String^ s) : Message(t, Color::Black, s) {
}

Message::Message(State t, Color msgColor, String^ s) : state(t), color(msgColor), content(s) {
	
}

Message::~Message() {
	delete content;
	
}

Message::operator String^ () {
	return this->content;
}

String ^ Message::ToString() {
	return this->content;
}

Message^ Message::useKeywordAsNameError(String^ var) {
	return gcnew Message(Message::State::ERROR, "Cannot use the keyword \"" + var + "\" as a variable name");

}

Message^ Message::varNotDefinedMsg(String^ var) {

	return gcnew Message(Message::State::ERROR, "Variable \"" + var + "\" is not defined");
}

Message^ Message::varAlreadyExistMsg(String^ var) {
	return gcnew Message(Message::State::ERROR, "Variable \"" + var + "\" already exist, please choosen another identifier");
}