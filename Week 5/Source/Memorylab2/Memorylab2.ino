const char string_0[] PROGMEM = "This is a String 0 Table 1: It is going to be stored in the memory. Check the memory capacity"; // "String 0" etc are strings to store - change to suit.
const char string_1[] PROGMEM = "This is a String 1 Table 1: It is going to be stored in the memory. Check the memory capacity";
const char string_2[] PROGMEM = "This is a String 2 Table 1: It is going to be stored in the memory. Check the memory capacity";
const char string_3[] PROGMEM = "This is a String 3 Table 1: It is going to be stored in the memory. Check the memory capacity";
const char string_4[] PROGMEM = "This is a String 4 Table 1: It is going to be stored in the memory. Check the memory capacity";
const char string_5[] PROGMEM = "This is a String 5 Table 1: It is going to be stored in the memory. Check the memory capacity";

const char string2_0[] PROGMEM = "This is a String 0 Table 2: It is going to be stored in the memory. Check the memory capacity"; 
const char string2_1[] PROGMEM = "This is a String 1 Table 2: It is going to be stored in the memory. Check the memory capacity";
const char string2_2[] PROGMEM = "This is a String 2 Table 2: It is going to be stored in the memory. Check the memory capacity";
const char string2_3[] PROGMEM = "This is a String 3 Table 2: It is going to be stored in the memory. Check the memory capacity";
const char string2_4[] PROGMEM = "This is a String 4 Table 2: It is going to be stored in the memory. Check the memory capacity";
const char string2_5[] PROGMEM = "This is a String 5 Table 2: It is going to be stored in the memory. Check the memory capacity";

const char string3_0[] PROGMEM = "This is a String 0 Table 3: It is going to be stored in the memory. Check the memory capacity"; 
const char string3_1[] PROGMEM = "This is a String 1 Table 3: It is going to be stored in the memory. Check the memory capacity";
const char string3_2[] PROGMEM = "This is a String 2 Table 3: It is going to be stored in the memory. Check the memory capacity";
const char string3_3[] PROGMEM = "This is a String 3 Table 3: It is going to be stored in the memory. Check the memory capacity";
const char string3_4[] PROGMEM = "This is a String 4 Table 3: It is going to be stored in the memory. Check the memory capacity";
const char string3_5[] PROGMEM = "This is a String 5 Table 3: It is going to be stored in the memory. Check the memory capacity";

const char string4_0[] PROGMEM = "This is a String 0 Table 4: It is going to be stored in the memory. Check the memory capacity"; 
const char string4_1[] PROGMEM = "This is a String 1 Table 4: It is going to be stored in the memory. Check the memory capacity";
const char string4_2[] PROGMEM = "This is a String 2 Table 4: It is going to be stored in the memory. Check the memory capacity";
const char string4_3[] PROGMEM = "This is a String 3 Table 4: It is going to be stored in the memory. Check the memory capacity";
const char string4_4[] PROGMEM = "This is a String 4 Table 4: It is going to be stored in the memory. Check the memory capacity";
const char string4_5[] PROGMEM = "This is a String 5 Table 4: It is going to be stored in the memory. Check the memory capacity";



const char *const string1_table[] PROGMEM = {string_0, string_1, string_2, string_3, string_4, string_5};

const char *const string2_table[] PROGMEM = {string2_0, string2_1, string2_2, string2_3, string2_4, string2_5};

const char *const string3_table[] PROGMEM = {string3_0, string3_1, string3_2, string3_3, string3_4, string3_5};

const char *const string4_table[] PROGMEM = {string4_0, string4_1, string4_2, string4_3, string4_4, string4_5};

char buffer[100]; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial); // wait for serial port to connect
  for (int i=0; i < 6; i++){
    for (int i = 0; i < 6; i++) {
    strcpy_P(buffer, (char *)pgm_read_word(&(string1_table[i])));
    Serial.println(buffer);
    strcpy_P(buffer, (char *)pgm_read_word(&(string2_table[i])));
    Serial.println(buffer);
    strcpy_P(buffer, (char *)pgm_read_word(&(string3_table[i])));
    Serial.println(buffer);
    strcpy_P(buffer, (char *)pgm_read_word(&(string4_table[i])));
    Serial.println(buffer);
    delay(500);
  }

  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
