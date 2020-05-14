#define CODE_LENGTH 4

class Code
{
public:

  char pattern[4];
  bool isSecret;
  int whitePegs;
  int blackPegs;

  Code(){
    isSecret = false;
    whitePegs = 0;
    blackPegs = 0;
  }

  void generateSecretCode();
  void compareCodes(Code*);
  void printSecret();
  int compareColors(int, int);
};
