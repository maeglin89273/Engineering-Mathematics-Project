#pragma once

namespace em {
	namespace intrprt {
		using System::Collections::Generic::Dictionary;

		generic <typename K, typename V>
		ref class MappingTable abstract {

		public:
			property const V default[K] {
				virtual const V get(K key) {
					return table[key];
				}
			}

		protected:
			Dictionary<K, V>^ table;

		public:
			virtual ~MappingTable();

			virtual bool contains(K key);

		protected:
			MappingTable();
		};
	}
}
