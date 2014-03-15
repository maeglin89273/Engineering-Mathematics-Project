#pragma once
namespace em {
	namespace intrprt {
		using System::String;
		using System::Drawing::Color;

		ref class Message {
		public:
			enum class State {
				ERROR, PASS, PARSING
			};

		public:
			property State msgState{
				virtual State get() sealed {
					return state;
				}
			}
			property String^ msgContent {
				virtual String^ get() sealed {
					return this->content;
				}
			}

			property Color msgColor{
				Color get() {
					return this->color;
				}
			}

			static property Message^ SYNTAX_ERROR_MSG {
				Message^ get() {
					return  gcnew Message(Message::State::ERROR, "wrong syntax, maybe it is not fit the format or argument type");
				}
			}

			static property Message^ PARSING_MSG{
				Message^ get() {
					return  gcnew Message(State::PARSING, nullptr);
				}

			}

			static property Message^ PASS_NO_CONTENT_MSG{
				Message^ get() {
					return  gcnew Message(State::PASS, nullptr);
				}

			}

			static const Color STORAGE_COLOR = Color::Blue;
			static const Color MATH_OBJECT_COLOR = Color::DarkGreen;
			static const Color SETTING_COLOR = Color::BlueViolet;
			static const Color COMMENT_COLOR = Color::Gray;

		private:
			State state;
			String^ const content;
			Color const color;
		
		public:
			Message(State t, String^ s);
			Message(State t, String^ s, Color msgColor);
			virtual ~Message();
			
			operator String^ ();
			virtual String^ ToString() override;

			static Message^ Message::varNotFoundMsg(String^ var);
			static Message^ Message::varAlreadyExistMsg(String^ var);

		};
	}
}
