void Check_start_end(String Digit_value) {
  if (check_code.length() < 8) {
    //받은 데이터 계속 합치고
    check_code.concat(Digit_value);
    //    delay(Delay_value);
  }
  else {
    check_code = check_code.substring(1);
    check_code.concat(Digit_value);

    //    Serial.println(check_code);

    //    delay(Delay_value);
  }
}

String Analog_to_Digital(int Analog) {
  if (Analog <= 80) {
//    Serial.println(Analog);
    return "1";
  }
  //  else if (115 < Analog && Analog <= 180 ){
  //    Serial.print("슈레기");
  //    Serial.println(Analog);
  //    return "";
  //  }
  else {
    return "0";
  }
}
