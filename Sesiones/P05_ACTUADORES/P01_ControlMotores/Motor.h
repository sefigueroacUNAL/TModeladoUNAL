

class Motor{

  public:


  int PIN_DIR;
  int PIN_ENABLE;

  int dir;
  int vel;

  Motor(int,int);

  void SetSpeed(int);
  void SetDir(int);
  void Stop();
  void Init();
  void Forward(int);
  void Backward(int);
  
  };
