#include <EEPROM.h>
//160 까지 기기정보 16칸
//161~168 비밀번호 8킨
//300     기기개수 1칸

//char **Stored_device_info;
//char *Stored_pwd;

const int Stored_device_number = 10;
const int Stored_deviceinfo_length = 16;
const int Stored_pwd_number = 1;
const int Stored_pwd_length = 8;

int device_count = 0;


char pwd_temp[8];
char deviceinfo_temp[16];

String Stored_device_info_str;
String Stored_pwd_str;

//void init_Stored_value() {
//  Stored_device_info = (char **) malloc (sizeof(char *) * Stored_device_number);
//  for(int i = 0; i < Stored_device_number; i++) {
//    Stored_device_info[i] = (char *) malloc (sizeof(char) * Stored_deviceinfo_length);
//  }
//
//  Stored_pwd = (char *) malloc (sizeof(char) * Stored_pwd_length);
//}

void write_count_EEPROM() {
  EEPROM.write(300, device_count);
}

void read_count_EEPROM() {
  int count = EEPROM.read(300);
  Serial.print("EEPROM에서 읽어온 기기개수: ");
  Serial.println(count);
}

void plus_count() {
  device_count++;
}

void write_device_info_EEPROM(String device_info) {
  char buf[Stored_deviceinfo_length + 1];
  device_info.toCharArray(buf, Stored_deviceinfo_length + 1);

  for (int i = 0; i < Stored_deviceinfo_length; i++) {
    EEPROM.write(i + (16 * device_count), buf[i]);
    //write(addr, value);
  }
  plus_count();
}

void read_device_info_EEPROM() {
  for (int i = 0; i < Stored_deviceinfo_length; i++) {
    deviceinfo_temp[i] = EEPROM.read(i);
  }
  Stored_device_info_str = deviceinfo_temp;
  Serial.print("EEPROM에서 읽어온 기기정보: ");
  Serial.println(Stored_device_info_str);
}

boolean search_EEPROM(String input, String type) {
  int divide;
  int length_val;
  int number;
  char *search_temp;
  int fork;
  
  if ( type.equals("deviceinfo") ) {
    fork = 0;
    divide = 16;
    length_val = Stored_deviceinfo_length;
    number = Stored_device_number;
    search_temp = (char *) malloc (sizeof(char) * Stored_deviceinfo_length);
    Serial.println("기기정보 서치");

  } else if ( type.equals("pwd") ) {
    fork = 1;
    divide = 8;
    length_val = Stored_pwd_length;
    number = Stored_pwd_number;
    search_temp = (char *) malloc (sizeof(char) * Stored_pwd_length);
    Serial.println("비번 서치");

  } else {
    Serial.println("Stored_info - search_EEPROM - 해당 type 없음 ");
  }

  for (int i = 0; i < (length_val * number) + 1; i++) {
    if ( i % divide == 0 && i != 0 ) {
      String search_temp_str = search_temp;
      search_temp_str = search_temp_str.substring(0, length_val);
      Serial.println(search_temp_str);
      
      if ( search_temp_str.equals(input) ) {
        Serial.print("EEPROM에 찾던 값 있음: ");
        Serial.println(search_temp_str);
        free(search_temp);
        return true;
      }
    }
    search_temp[i % divide] = EEPROM.read( (160 * fork) + i );
    
  }

  Serial.println("없얼");
  free(search_temp);
  return false;
}

void write_pwd_EEPROM(String pwd) {
  char buf[Stored_pwd_length + 1];
  pwd.toCharArray(buf, Stored_pwd_length + 1);

  for (int i = 0; i < Stored_pwd_length; i++) {
    EEPROM.write(160 + i, buf[i]);
    //write(addr, value);
  }
}

void read_pwd_EEPROM() {
  for (int i = 0; i < Stored_pwd_length; i++) {
    pwd_temp[i] = EEPROM.read(160 + i);
  }
  Stored_pwd_str = pwd_temp;
  Serial.print("EEPROM에서 읽어온 비밀번호: ");
  Serial.println(Stored_pwd_str);
}

void clear_EEPROM() {
  for (int i = 0 ; i < 350 ; i++) {
    EEPROM.write(i, 0);
  }
}
