#pragma once
#include <string>
#include <functional>
#include <list>

using namespace std;
namespace ejemplo_mvc {
	class Student;

	using Listener = function<void(const Student&)>;
	using Connection = list<Listener>::iterator;

	class Student {
	public:
		const string& getName() const {
			return name;
		}
		void setName(const string& name) {
			this->name = name;
			notify();
		}
		const string& getNollNo() const {
			return nollNo;
		}
		void setNollNo(const string& nollNo) {
			this->nollNo = nollNo;
			notify();
		}

		Connection connect(Listener l) {
			return listeners_.insert(listeners_.end(), l);
		}

		// TODO: La conexión no se elimina de la lista.
		void disconnect(Connection c) {
			listeners_.erase(c);
		}

		void notify() const {
			for (const auto& listener : listeners_)
				listener(*this);
		}
	private:
		string nollNo;
		string name;

		// http://www.cplusplus.com/reference/list/list
		list<Listener> listeners_;
	};
};
