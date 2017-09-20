class House
{
public:
  House(int size = 3, char border = 'X', char fill = '*');

  int GetSize(), Perimeter();
  double Area();

  void Grow(), Shrink();
  void SetBorder(char border);
  void SetFill(char fill);
  void Draw();
  void Summary();

private:
  int baseSize;
  char borderChar, fillChar;
};
