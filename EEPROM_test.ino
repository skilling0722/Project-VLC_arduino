//#include <EEPROM.h>
//
//char **Stored_device_info;
//
//char test[] = {'a','b','c','f'};
//
//void init_Stored_value(){
//  Stored_device_info = (char**)malloc (sizeof(char *) * 10);
//  Stored_device_info[0] = (char*)malloc(sizeof(char) * 150);
//
//  for(int i = 0 ; i < sizeof(test); i++) {
//    Stored_device_info[0][i] = test[i];
//  }
//}
//
//
//void write_test(){
//  for(int i = 0; i < sizeof(test); i++) {
//    EEPROM.write(i,Stored_device_info[0][i]); 
//  }
//}
//
//void read_test() {
//  for(int i = 0; i < sizeof(test); i++) {
//    char value = EEPROM.read(i);
//    Serial.print(value);
//  }
//
//  
//}
