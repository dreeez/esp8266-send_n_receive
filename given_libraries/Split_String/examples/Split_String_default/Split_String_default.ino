#include <Split_String.h> // Include the Library in the Code

Split_String split;

void setup() { // Code runs once (startup)
  String example_string = "firstValue:secondValue"; // The example String

  String value1 = split.brakestring(example_string, ':', 0); // Splits the String in: "first value"
  String value2 = split.brakestring(example_string, ':', 1); // Splits the String in: "second value"

  Serial.begin(9600);
  Serial.println(); Serial.println(); // Creates a spacer under the Start of Serial
  Serial.print("example_string: "); Serial.println(example_string); // Prints out the "example_string" String
  Serial.print("VALUE 1:        "); Serial.println(value1); // Prints the first Form Variable from the String
  Serial.print("VALUE 2:        "); Serial.println(value2); // Prints the second Form Variable from the String
  Serial.print("COMBINED AGAIN: "); Serial.print(value1); Serial.print(":"); Serial.print(value2); // Combinds the Strings again in the console
  // ! Look in the console to see the effect !
}

void loop() { // Code runs repeatedly (forever)
  // Some code
}