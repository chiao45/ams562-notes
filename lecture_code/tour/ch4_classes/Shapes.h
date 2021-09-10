#include <vector>

struct Point {
  double xp, yp;
  Point(double x, double y) : xp(x), yp(y) {} // default constructor
};

class Shape {
public:
  virtual Point center() const = 0; // pure virtual
  virtual void move(Point to) = 0;

  virtual void draw() const = 0; // draw on "Canvas"
  virtual void rotate(int angle) = 0;

  virtual ~Shape() {} // destructor
  //
};

// function to vector of pointers to shape passed by reference
// no matter the type of shape we can call rotate
void rotate_all(std::vector<Shape *> &v,
                int angle) // rotate v's elements by angle degrees
{
  for (auto p : v)
    p->rotate(angle);
}

class Circle : Shape {
public:
  Circle(Point p, int rad); // Constructor

  Point center() const override { return x; }
  void move(Point to) override { x = to; }
  void draw() const override;
  void rotate(int) override {}

private:
  Point x; // center
  int r;   // radius
};

class Smiley : public Circle {
public:
  Smiley(Point p, int rad) : Circle{p, rad}, mouth{nullptr} {}
  // Circle with p center and radius r
  ~Smiley() {
    delete mouth;
    for (auto p : eyes)
      delete p;
  }
  void move(Point to) override;

  void draw() const override;
  void rotate(int) override;
  void add_eye(Shape *s) { eyes.push_back(s); }
  void set_mouth(Shape *s);
  virtual void wink(int i);

private:
  std::vector<Shape *> eyes;
  Shape *mouth;
};
void Smiley::draw() const {
  Circle::draw();
  for (auto p : eyes)
    p->draw();
  mouth->draw();
}

enum class Kind { circle, triangle, smiley };

Shape *read_shape(std::istream &is) {

  switch (k) {
  case ::Kind::circle:
    return new Cirle{p, r} caseK
  }
}
