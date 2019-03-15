
boolean Check_end() {
  if (check_code.length() == 8) {
    if (check_code.equals(exit_code)) {
      Serial.println("종료꺼");
      Serial.println(check_code);
      //      Serial.println("종료 ㅇㅋ");
      //반복-센서 작동 데이터 받기 시작
      return true;
    }
    else {
      //      Serial.println("종료 패스");
      return false;
    }
  } else {
    return false;
  }
}

boolean Check_begin() {
  if (check_code.length() == 8) {
    if (check_code.equals(pre_amble_code)) {
      Serial.println(check_code);
                  Serial.println("프리앰블 ㅇㅋ");
      //반복-센서 작동 데이터 받기 시작
      return true;
    }
    else {
      //      Serial.println("프리앰블 패스");
      return false;
    }
  } else {
    return false;
  }
}
