#pragma once
#include "MathObjSet.h"

namespace em {
	namespace math {
		using namespace System::Collections::Generic;
		using System::Text::StringBuilder;

		generic<typename M> where M : MathObject
		ref class MathObjGenericSet : public MathObjSet, public IEnumerable<M> {

		private:
			LinkedList<M>^ list;

		public:
			property MathObject^ clone{
				virtual MathObject^ get() override {
					return gcnew MathObjGenericSet<M>(this);
				}
			}

			property int size{
				virtual int get() override {
					return list->Count;
				}
			}
		public:
			MathObjGenericSet(String^ objID);
			MathObjGenericSet(MathObjGenericSet<M>^ set);
			virtual ~MathObjGenericSet();
			
			virtual bool add(MathObject^ mo) override;
			virtual String^ ToString() override;
			virtual MathObject^ operator-() override;

			virtual IEnumerator<M>^ GetEnumerator();
			virtual void add(M mo);
			
			static bool gSetCast(MathObject^ mo, MathObjGenericSet<M>^% set);

		private:
			virtual System::Collections::IEnumerator^ GetNGEnumerator() sealed = System::Collections::IEnumerable::GetEnumerator;
			MathObjGenericSet<M>^ emptyClone();
		};

	}
}