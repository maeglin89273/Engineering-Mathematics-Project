#include "MathObjSet.h"
#include "PrintCommand.h"

using namespace em::math;
using em::intrprt::cmd::PrintCommand;

MathObjSet::MathObjSet(String^ contentID) : MathObject(TAG, getVaildContentID(contentID)+ ID) {
}

MathObjSet::~MathObjSet() {
}


bool MathObjSet::setCast(MathObject^ mo, MathObjSet^% set) {
	set = dynamic_cast<MathObjSet^>(mo);
	return set != nullptr;
}

String^ MathObjSet::getVaildContentID(String^ contentID) {
	return contentID[contentID->Length - 1].ToString();
}

static MathObjSet::MathObjSet() {
	setConstructors->Add(Scalar::TAG, gcnew ConcreteSet(createSetInstance<Scalar^>));
	setConstructors->Add(Vector::TAG, gcnew ConcreteSet(createSetInstance<Vector^>));
	setConstructors->Add(Matrix::TAG, gcnew ConcreteSet(createSetInstance<Matrix^>));
	setConstructors->Add(MathObjSet::TAG, gcnew ConcreteSet(createSetInstance<MathObjSet^>));
}

MathObjSet^ MathObjSet::createSpecificSet(MathObject^ element) {
	return setConstructors[element->mathType](element->mathID);
}

