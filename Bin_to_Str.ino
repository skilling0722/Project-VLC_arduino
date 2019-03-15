String toStr(String tmp_data) {
    char tmp[8];
    String res_data= "";
    int i, j, val;
    for(i=0; i<tmp_data.length(); i=i+8){
      val = 0;
      for(j=0; j<8; j++){
        val *= 2; 
        if (tmp_data[i+j] == '1') val++; 
      }
      res_data += (char)val;
    }
    return res_data;
}
