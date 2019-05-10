#include <iostream>

using namespace std;
namespace ns_chapter_4_9 {
	class StrategyInterface {
	public:
		virtual void execute() const = 0;
	};
	class ConcreteStrategyA : public StrategyInterface {
	public:
		void execute() const override {
			cout << "-> CalledConcreteStrategyA execute method" << endl;
		}
	};
	class ConcreteStrategyB : public StrategyInterface {
	public:
		void execute() const override {
			cout << "-> CalledConcreteStrategyB execute method" << endl;
		}
	};
	class ConcreteStrategyC : public StrategyInterface {
	public:
		void execute() const override {
			cout << "-> CalledConcreteStrategyC execute method" << endl;
		}
	};
	class Context {
	private:
		StrategyInterface* strategy_;
	public:
		explicit Context(StrategyInterface* strategy) : strategy_(strategy) {}
		void set_strategy(StrategyInterface* strategy) {
			strategy_ = strategy;
		}
		void execute() const {
			strategy_->execute();
		}
	};
}

inline void chapter_4_9() {
	cout << "Strategy" << endl;
	cout << "--------" << endl;

	using namespace ns_chapter_4_9;
	ConcreteStrategyA concreteStrategyA;
	ConcreteStrategyB concreteStrategyB;
	ConcreteStrategyC concreteStrategyC;

	Context contextA(&concreteStrategyA);
	Context contextB(&concreteStrategyB);
	Context contextC(&concreteStrategyC);

	contextA.execute();
	contextB.execute();
	contextC.execute();

	contextA.set_strategy(&concreteStrategyB);
	contextA.execute();
	contextA.set_strategy(&concreteStrategyC);
	contextA.execute();
}