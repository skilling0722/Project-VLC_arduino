void start_device_registration() {
  Serial.println("기기 등록 시작");
    
  Serial.print("기기정보: ");
  Serial.println(Data);

  Serial.print("복원기기정보:");
  Serial.println(toStr(Data));
}

void start_pwd_change() {
  Serial.println("비번 변경 시작");
    
  String device_info = Data.substring(0, 128);
  String old_pwd = Data.substring(128, 192);
  String new_pwd = Data.substring(192, 256);

  Serial.print("기기정보: ");
  Serial.println(device_info);

  Serial.print("복원기기정보:");
  Serial.println(toStr(device_info));
    
  Serial.print("기존비번: ");
  Serial.println(old_pwd);

  Serial.print("복원기존비번:");
  Serial.println(toStr(old_pwd));
    
  Serial.print("변경비번: ");
  Serial.println(new_pwd);

  Serial.print("복원변경비번:");
  Serial.println(toStr(new_pwd));
}

void start_open_door() {
  Serial.println("문 열기 시작");

  String device_info = Data.substring(0, 128);
  String pwd = Data.substring(128, 192);

  Serial.print("기기정보: ");
  Serial.println(device_info);

  Serial.print("복원기기정보:");
  Serial.println(toStr(device_info));
    
  Serial.print("비번: ");
  Serial.println(pwd);

  Serial.print("복원비번:");
  Serial.println(toStr(pwd));
}
