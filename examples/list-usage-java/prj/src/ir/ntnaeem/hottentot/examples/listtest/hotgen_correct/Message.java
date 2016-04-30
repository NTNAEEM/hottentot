///******************************************************************
// * Generated by Hottentot JAVA Generator
// * Date:
// * Name:
// * Description:
// *   This file contains definition of an abstract service class.
// ******************************************************************/
//package ir.ntnaeem.hottentot.examples.listtest.hotgen;
//
//import ir.ntnaeem.hottentot.serializerHelper.PDTSerializer;
//import ir.ntnaeem.hottentot.serializerHelper.PDTDeserializer;
//import ir.ntnaeem.hottentot.serializerHelper.ByteArrayToInteger;
//
//public class Message {
//  private String value = "";
//  private String desc = "";
//  private short len;
//  public void setValue(String value) {
//    this.value = value;
//  }
//  public String getValue() {
//    return value;
//  }
//  public void setDesc(String desc) {
//    this.desc = desc;
//  }
//  public String getDesc() {
//    return desc;
//  }
//  public void setLen(short len) {
//    this.len = len;
//  }
//  public short getLen() {
//    return len;
//  }
//  @Override
//  public String toString() {
//    return "Message{" +
//      "value = '" + value + '\'' +
//      ",desc = '" + desc + '\'' +
//      ",len = '" + len + '\'' +
//      "}";
//  }
//
//  public byte[] serialize() {
//    byte[] serializedValue = PDTSerializer.getString(value);
//    byte[] serializedDesc = PDTSerializer.getString(desc);
//    byte[] serializedLen = PDTSerializer.getInt16(len);
//    byte[] output = new byte[serializedValue.length + serializedDesc.length + serializedLen.length];
//    int counter = 0;
//    //use a loop for every property
//    for (int i = 0; i < serializedValue.length; i++) {
//      output[counter++] = serializedValue[i];
//    }
//    for (int i = 0; i < serializedDesc.length; i++) {
//      output[counter++] = serializedDesc[i];
//    }
//    for (int i = 0; i < serializedLen.length; i++) {
//      output[counter++] = serializedLen[i];
//    }
//    return output;
//  }
//
//  public void deserialize(byte[] serializedByteArray) {
//    if(serializedByteArray.length != 0){
//      int counter = 0;
//      int dataLength = 0;
//      int numbersOfBytesForDataLength;
//      //do for every property
//    //value : String
//    dataLength = 0;
//    if(( serializedByteArray[counter] & 0x80) == 0 ) {
//      dataLength = serializedByteArray[counter++];
//    }else{
//      numbersOfBytesForDataLength = serializedByteArray[counter++] & 0x0f;
//      byte[] serializedByteArrayLength = new byte[numbersOfBytesForDataLength];
//      for(byte i = 0 ; i < numbersOfBytesForDataLength ; i++){
//        serializedByteArrayLength[i] = serializedByteArray[counter++];
//      }
//      dataLength = ByteArrayToInteger.getInt(serializedByteArrayLength);
//    }
//    byte[] valueByteArray = new byte[dataLength];
//    System.arraycopy(serializedByteArray,counter,valueByteArray,0,dataLength);
//    counter += dataLength;
//    setValue(PDTDeserializer.getString(valueByteArray));
//    //desc : String
//    dataLength = 0;
//    if(( serializedByteArray[counter] & 0x80) == 0 ) {
//      dataLength = serializedByteArray[counter++];
//    }else{
//      numbersOfBytesForDataLength = serializedByteArray[counter++] & 0x0f;
//      byte[] serializedByteArrayLength = new byte[numbersOfBytesForDataLength];
//      for(byte i = 0 ; i < numbersOfBytesForDataLength ; i++){
//        serializedByteArrayLength[i] = serializedByteArray[counter++];
//      }
//      dataLength = ByteArrayToInteger.getInt(serializedByteArrayLength);
//    }
//    byte[] descByteArray = new byte[dataLength];
//    System.arraycopy(serializedByteArray,counter,descByteArray,0,dataLength);
//    counter += dataLength;
//    setDesc(PDTDeserializer.getString(descByteArray));
//    //len : short
//    byte[] lenByteArray = new byte[2];
//    for(int i = 0 ; i < 2 ; i++){
//      lenByteArray[i] = serializedByteArray[counter++];
//    }
//    setLen(PDTDeserializer.getInt16(lenByteArray));
//
//    }
//  }
//}
