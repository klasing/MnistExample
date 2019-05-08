#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <memory>

using namespace std;
namespace ns_chapter_4_8 {
	enum Input {DUCK_DOWN, STAND_UP, JUMP, DIVE};

	class Fighter;
	class StandingState; class JumpingState; class DivingState;

	class FighterState {
	public:
		static shared_ptr<StandingState> standing;
		static shared_ptr<DivingState> diving;
		virtual ~FighterState() = default;
		virtual void handleInput(Fighter&, Input) = 0;
		virtual void update(Fighter&) = 0;
	};

	class DuckingState : public FighterState {
	private:
		int chargingTime;
		static const int FullRestTime = 5;
	public:
		DuckingState() : chargingTime(0) {}
		virtual void handleInput(Fighter&, Input) override;
		virtual void update(Fighter&) override;
	};

	class StandingState : public FighterState {
	public:
		virtual void handleInput(Fighter&, Input) override;
		virtual void update(Fighter&) override;
	};

	class JumpingState : public FighterState {
	private:
		int jumpingHeight;
	public:
		JumpingState() { jumpingHeight = rand() % 5 + 1; }
		virtual void handleInput(Fighter&, Input) override;
		virtual void update(Fighter&) override;
	};

	class DivingState : public FighterState {
	public:
		virtual void handleInput(Fighter&, Input) override;
		virtual void update(Fighter&) override;
	};

	//shared_ptr<StandingState> FighterState::standing(new StandingState);
	//shared_ptr<DivingState> FighterState::diving(new DivingState);

	class Fighter {
	private:
		string name;
		shared_ptr<FighterState> state;
		int fatiqueLevel = rand() % 10;
	public:
		Fighter(const string& newName) : name(newName), state(FighterState::standing) {}
		string getName() const { return name; }
		int getFatiqueLevel() const { return fatiqueLevel; }
		// delegate input handling to 'state'
		virtual void handleInput(Input input) { state->handleInput(*this, input); }
		void changeState(shared_ptr<FighterState> newState) {
			state = newState;
			updateWithNewState();
		}
		void standsUp() { cout << "-> " << getName() << "  stands up." << endl; }
		void ducksDown() { cout << "-> " << getName() << "  ducks down." << endl; }
		void jumps() { cout << "-> " << getName() << "  jumps into the air." << endl; }
		void dives() { cout << "-> " << getName() << "  makes a dive attack in the middle of the jump!" << endl; }
		void feelsStrong() { cout << "-> " << getName() << "  feels strong!" << endl; }
		void changeFatiqueLevelBy(int change) { 
			fatiqueLevel += change;
			cout << "-> fatiqueLevel = " << fatiqueLevel << endl;
		}
	private:
		// delegate updating to 'state'
		virtual void updateWithNewState() { state->update(*this); }
	};

	inline void StandingState::handleInput(Fighter& fighter, Input input) {
		switch (input) {
		case STAND_UP:
			cout << "-> " << fighter.getName() << "  remains standing." << endl;
			return;
		case DUCK_DOWN:
			fighter.changeState(shared_ptr<DuckingState>(new DuckingState));
			return fighter.ducksDown();
		case JUMP:
			fighter.jumps();
			return fighter.changeState(shared_ptr<JumpingState>(new JumpingState));
		default:
			cout << "-> One cannot do that while standing. " << fighter.getName()
				<< " remains standing by default." << endl;
		} // eof switch
	}
	inline void StandingState::update(Fighter& fighter) {
		if (fighter.getFatiqueLevel() > 0)
			fighter.changeFatiqueLevelBy(-1);
	}

	inline void DuckingState::handleInput(Fighter& fighter, Input input) {
		switch (input) {
		case STAND_UP:
			fighter.changeState(FighterState::standing);
			return fighter.standsUp();
		case DUCK_DOWN:
			cout << "-> " << fighter.getName() << " remains in ducking position, ";
			if (chargingTime < FullRestTime)
				cout << "recovering in the meantime." << endl;
			else
				cout << "fully recovered." << endl;
			return update(fighter);
		default:
			cout << "-> One cannot do that while ducking. " << fighter.getName()
				<< " remains in ducking position by default." << endl;
			update(fighter);
		} // eof switch
	}

	inline void DuckingState::update(Fighter& fighter) {
		chargingTime++;
		cout << "-> Charching time = " << chargingTime << "." << endl;
		if (fighter.getFatiqueLevel() > 0)
			fighter.changeFatiqueLevelBy(-1);
		if (chargingTime >= FullRestTime && fighter.getFatiqueLevel() <= 3)
			fighter.feelsStrong();
	}

	inline void JumpingState::handleInput(Fighter& fighter, Input input) {
		switch (input) {
		case DIVE:
			fighter.changeState(FighterState::diving);
			return fighter.dives();
		default:
			cout << "-> One cannot do that in the middle of a jump. " << fighter.getName()
				<< " lands from his jump and is now standing again." << endl;
			fighter.changeState(FighterState::standing);
		} // eof switch
	}

	inline void JumpingState::update(Fighter& fighter) {
		cout << "-> " << fighter.getName() << " has jumped " << jumpingHeight
			<< " feet into the air." << endl;
		if (jumpingHeight >= 3)
			fighter.changeFatiqueLevelBy(1);
	}

	inline void DivingState::handleInput(Fighter& fighter, Input) {
		cout << "-> Regardless of what the user input is, " << fighter.getName()
			<< " lands from his dive and is now standing again." << endl;
		fighter.changeState(FighterState::standing);
	}

	inline void DivingState::update(Fighter& fighter) {
		fighter.changeFatiqueLevelBy(2);
	}
}
inline void chapter_4_8() {
	cout << "State" << endl;
	cout << "-----" << endl;

	using namespace ns_chapter_4_8;
	srand(time(nullptr));
	Fighter rex("Rex the Fighter"), borg("Borg the Fighter");
	cout << "-> " << rex.getName() << " and " << borg.getName() << " are currently standing." << endl;
	int choice;
	auto chooseAction = [&choice](Fighter & fighter) {
		cout << endl
			<< DUCK_DOWN + 1 << ") Duck down  "
			<< STAND_UP + 1 << ") Stand up  "
			<< JUMP + 1 << ") Jump  "
			<< DIVE + 1 << ") Dive in the middle of a jump" << endl;
		cout << "-> Choice for " << fighter.getName() << "? ";
		cin >> choice;
		const Input input1 = static_cast<Input>(choice - 1);
		fighter.handleInput(input1);
	};
	while (true) {
		chooseAction(rex);
		chooseAction(borg);
	}
}