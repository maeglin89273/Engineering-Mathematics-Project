#pragma once
#include "Command.h"
#include "All_Math.h"

namespace em {
	namespace intrprt {
		namespace cmd {
			using namespace em::intrprt;
			using System::String;
			using System::Text::StringBuilder;
			using em::math::MathObject;

			ref class PrintCommand : public Command {
			
			public:
				PrintCommand();
				virtual ~PrintCommand();

				virtual Message^ performCommand(String^ arg, Interpreter^ iptr) override;
				
				static StringBuilder^ buildHeader(MathObject^ mo, String^ vName);
				static StringBuilder^ PrintCommand::buildHeader(MathObject^ mo);
			};
		}
	}
}