const char string1[] PROGMEM = "This is a String 1";  // array1 global
const char string2[] = "This is a String 2"; // array2 global

char g = 0x20; // global

void testfun(char a){
  char b = g; 
  Serial.print("The value of a inside testfun function is "); // local variable 
  Serial.println(a, HEX);
  Serial.print("The location of a inside testfun function is at"); // local variable 
  Serial.println((int) &a, HEX);
  Serial.print("The value of local b inside testfun function is ");// local variable 
  Serial.println(b, HEX);
  Serial.print("The location of local b inside testfun function is at ");// local variable 
  Serial.println((int) &b, HEX);
  Serial.print("The value of global g inside testfun function is ");// global variable 
  Serial.println(g, HEX);
  Serial.print("The locaion of global g inside testfun function is at ");// global  variable 
  Serial.println((int) &g, HEX);
  }
  
void setup()
{
  // put your setup code here, to run once:
  char a = 0x22; // a in setup
  char *ptr; // a pointer in setup
  ptr = &a; // a in setup
  char string3[] = "This is a String 3"; // array3 in setup 
  char *string4; // array4 in setup 
  string4 = (char *) malloc(strlen("This is a String 4") +1); // dynamically allocate 
  strcpy(string4,"This is a String 4");

  
  Serial.begin(9600);
  while (!Serial);
  //String
  Serial.print("The String 1 address is ");
  Serial.println((int) string1, HEX);
  Serial.print("The String 2 address is ");
  Serial.println((int) string2, HEX);
  Serial.print("The String 3 address is ");
  Serial.println((int) string3, HEX);
  Serial.print("The String 4 address is ");
  Serial.println((int) string4, HEX);
  Serial.println();

  void (*fun_ptr)(char) = &testfun; // Assign the function as a pointer 
  (*fun_ptr)(0x30); // call the function vs point
  Serial.print("The location of testfun function is at " );
  Serial.println((int) &testfun, HEX);
  Serial.print("The location of fun_ptr is at " );
  Serial.println((int) fun_ptr, HEX);
  Serial.println();

  // vaiable, a, b, c, g
  Serial.print("The location of a in setup is at " );
  Serial.println((int) &a, HEX);
  Serial.print("The location of *ptr in setup is at " );
  Serial.println((int) ptr, HEX);
  Serial.print("The location of ptr in setup is at " );
  Serial.println((int) &ptr, HEX);
  Serial.print("The value of a in setup is" );
  Serial.println(a, HEX);
  Serial.print("The content of ptr in setup is " );
  Serial.println((int) ptr, HEX);
  Serial.print("The content of *ptr in setup is " );
  Serial.println(*ptr, HEX);
  Serial.print("The location of g in setup is at " );
  Serial.println((int) &g, HEX);
  Serial.print("The value of g in setup is " );
  Serial.println(g, HEX);

   free(string4); // free memory location reserved for string 4
  }


void loop() {
  // put your main code here, to run repeatedly:

}
