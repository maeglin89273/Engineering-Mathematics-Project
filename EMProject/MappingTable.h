#pragma once

namespace em {
	namespace intrprt {
		using System::Collections::Generic::Dictionary;

		generic <typename K, typename V>
		ref class MappingTable abstract {
		protected:
			Dictionary<K, V>^ table;
		public:
			virtual property const V default[K] {
				const V get(K key) {
					return table[key];
				}
			}

			MappingTable();
			virtual ~MappingTable();

			virtual bool contains(K key) sealed;
		};
	}
}
