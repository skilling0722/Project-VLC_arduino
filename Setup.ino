int photodiode_pin_anal = A0;

int Analog_value;
String Digit_value;

String check_code = "";

String pre_amble_code = "10000001";
String exit_code = "10000001";

float Delay_value = 1;

String Analog_to_Digital(int Analog);

String Data;

unsigned long pre_time = 0;
const long interval = 500;

unsigned long sum_Analog_value = 0;
unsigned long cnt = 0;

void setup() {
  Serial.begin(230400);
  pinMode(photodiode_pin_anal, INPUT);
}

void loop() {
//  init_Stored_value();
//  write_test();
//  read_test();

//  init_Stored_value();

//  clear_EEPROM();
  
  write_device_info_EEPROM("HelloHelloHello1");
  read_device_info_EEPROM();

  write_device_info_EEPROM("HelloHelloHello2");
  
  write_pwd_EEPROM("aaaa1111");
  read_pwd_EEPROM();

  write_count_EEPROM();
  read_count_EEPROM();

  search_EEPROM("HelloHelloHello1", "deviceinfo");
  search_EEPROM("aaaa1111", "pwd");
  search_EEPROM("HelloHelloHello2", "deviceinfo");
  
  delay(1000000000);
  
  Analog_value = analogRead(photodiode_pin_anal);


  unsigned long current_time = millis();
  //  Serial.println(current_time);
  //  Serial.println();
  //  Serial.println(pre_time);
  cnt++;
  sum_Analog_value += Analog_value;

  if ( current_time - pre_time >= interval ) {
    //    pre_time = current_time;
    Analog_value = sum_Analog_value / cnt;

    cnt = 0;
    sum_Analog_value = 0;

//    Serial.print("변환전 값");
//    Serial.println(Analog_value);

    Digit_value = Analog_to_Digital(Analog_value);

    Check_start_end(Digit_value);

    pre_time = current_time;

    if (Check_begin()) {
      //반복-센서 작동 데이터 받기 시작
      Receive_Data();
      Serial.end(); // 테스트할때만
    }
  }
}
