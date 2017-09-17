class House
{
public:
  House();
  House(int size = 3, char border = 'X', char fill = '*');

  int GetSize(), Perimeter();
  double Area();

  void Grow(), Shrink();
  void SetBorder(char border), SetFill(char fill);
  void Draw();
  void Summary();

private:
  double baseSize;
  char borderChar, fillChar;
};
