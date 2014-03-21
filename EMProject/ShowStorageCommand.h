#pragma once
#include "Command.h"

namespace em {
	namespace intrprt {
		namespace cmd {
			using namespace System::Collections::Generic;

			ref class ShowStorageCommand : public Command {
			private:
				Dictionary<String^, String^>^ map;

			public:
				ShowStorageCommand();
				virtual ~ShowStorageCommand();

				virtual Message^ performCommand(String^ arg, Interpreter^ iptr) override;
			};
		}
	}
}