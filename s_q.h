#define str_q

using namespace std;

class string_queue{
  private:
    string* data;
    int size;
    int capacity;
    int begin;
    int end;
  public:
    string_queue(const int cap);
    ~string_queue();
    void push(const string x);
    string pop();
    string operator[] (int x);
    int get_end();
    int get_begin();
};




string_queue::string_queue(const int cap){
  capacity = cap;
  begin = end = size = 0;
  data = new string[capacity + 1];
}

int string_queue::get_end(){
  return end;
}

int string_queue::get_begin(){
  return begin;
}

string string_queue::operator[] (int n){
  return data[n];
}

string_queue::~string_queue{
  delete [] data;
}

void string_queue::push(const string x){
  if(size >= capacity){
    capacity*= 2;
    string* temp = new string[capacity];
    for(unsigned int i = 0; i < size; i++){
      temp[i] = data[i];
    }
    delete [] data;
    data = temp;
  }
  data[end++] = x;
}

string string_queue::pop(){
  size--;
  return data[begin++];
}