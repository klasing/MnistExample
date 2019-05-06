#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Graphic_3_3 {
public:
	virtual void print() const = 0;
	virtual ~Graphic_3_3() {}
};

class Ellipse_3_3 : public Graphic_3_3 {
public:
	void print() const {
		cout << "-> Ellipse\n";
	}
};

class CompositeGraphic_3_3 : public Graphic_3_3 {
public:
	void print() const {
		for (Graphic_3_3* a : graphicList_)
			a->print();
	}

	void add(Graphic_3_3* aGraphic) {
		graphicList_.push_back(aGraphic);
	}
private:
	vector<Graphic_3_3*> graphicList_;
};

inline void chapter_3_3() {
	cout << "Composite" << endl;
	cout << "---------" << endl;

	// Initialize four ellipses
	const unique_ptr<Ellipse_3_3> ellipse1(new Ellipse_3_3());
	const unique_ptr<Ellipse_3_3> ellipse2(new Ellipse_3_3());
	const unique_ptr<Ellipse_3_3> ellipse3(new Ellipse_3_3());
	const unique_ptr<Ellipse_3_3> ellipse4(new Ellipse_3_3());

	// Initialize three composite graphics
	const unique_ptr<CompositeGraphic_3_3> graphic(new CompositeGraphic_3_3());
	const unique_ptr<CompositeGraphic_3_3> graphic1(new CompositeGraphic_3_3());
	const unique_ptr<CompositeGraphic_3_3> graphic2(new CompositeGraphic_3_3());

	// Composes the graphics
	graphic1->add(ellipse1.get());
	graphic1->add(ellipse2.get());
	graphic1->add(ellipse3.get());

	graphic2->add(ellipse4.get());

	graphic->add(graphic1.get());
	graphic->add(graphic2.get());

	// Prints the complete graphic (four times the string "Ellipse")
	graphic->print();
}