void Receive_Data() {
  while (1) {
    Analog_value = analogRead(photodiode_pin_anal);


    //    Serial.println(Analog_value);

    unsigned long current_time = millis();
    cnt++;

    sum_Analog_value += Analog_value;

    if ( current_time - pre_time >= interval ) {
      pre_time = current_time;

      Analog_value = sum_Analog_value / cnt;

      cnt = 0;
      sum_Analog_value = 0;

      Serial.print("데이터값");
      Serial.println(Analog_value);

      Digit_value = Analog_to_Digital(Analog_value);

      Check_start_end(Digit_value);

      Data.concat(Digit_value);

      if (Check_end()) {
        Data = Data.substring(0, Data.length() - exit_code.length());
        
        Serial.print("데이터: ");
        Serial.println(Data);
        Serial.print("길이: ");
        Serial.println(Data.length());
        
        Restore_Data(&Data);
        Serial.print("프리앰블 중복 처리 완:");
        Serial.println(Data);

        String Data_type_bit = Catch_datatype(&Data);
        Serial.print("종류: ");
        Serial.println(Data_type_bit);
        
        
        //종류비트에 따라 분기
        fork(Data_type_bit);
        
//        Serial.print("실제 데이터: ");
//        Serial.println(Data);
//
//        Serial.print("toString:");
//        Serial.println(toStr(Data));
        
        break;
      }
    }
  }
}
void fork(String Data_type_bit) {
  if ( Data_type_bit.equals("001") ) {
    //기기 등록 시작
    start_device_registration();
    
  } else if ( Data_type_bit.equals("010") ) {
    //비번 변경 시작
    start_pwd_change();

  } else if ( Data_type_bit.equals("011") ) {
    //문 열기 시작
    start_open_door();
    
  } else {
    Serial.println("해당되는 종류 비트 없음. 에러 ");
  }
}

void Restore_Data(String *Data) {
  (*Data).replace("000001", "00000");
}

String Catch_datatype(String *Data) {
  String temp = (*Data).substring(0, 3);
  (*Data).remove(0, 3);
  return temp;
}
