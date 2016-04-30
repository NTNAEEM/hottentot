///******************************************************************
// * Generated by Hottentot JAVA Generator
// * Date:
// * Name:
// * Description:
// *
// ******************************************************************/
//package ir.ntnaeem.hottentot.examples.listtest.hotgen;
//
//import ir.ntnaeem.hottentot.runtime.Argument;
//import ir.ntnaeem.hottentot.runtime.Request;
//import ir.ntnaeem.hottentot.runtime.RequestHandler;
//import ir.ntnaeem.hottentot.runtime.Response;
//import ir.ntnaeem.hottentot.runtime.Service;
//import ir.ntnaeem.hottentot.runtime.config.Config;
//import ir.ntnaeem.hottentot.runtime.exception.MethodNotSupportException;
//import ir.ntnaeem.hottentot.runtime.exception.TcpClientConnectException;
//import ir.ntnaeem.hottentot.runtime.exception.TcpClientReadException;
//import ir.ntnaeem.hottentot.runtime.exception.TcpClientWriteException;
//import ir.ntnaeem.hottentot.serializerHelper.PDTDeserializer;
//import ir.ntnaeem.hottentot.serializerHelper.PDTSerializer;
//import ir.ntnaeem.hottentot.type._String;
//
//import java.util.List;
//
//public class ListTestRequestHandler extends RequestHandler {
//  public ListTestRequestHandler(Service service) {
//    super(service);
//  }
//  @Override
//  public Response handleRequest(Request request) throws TcpClientWriteException, TcpClientReadException, TcpClientConnectException, MethodNotSupportException {
//    long methodId = request.getMethodId();
//    ListTestService listTestImpl = (AbstractListTestService) service;
//    if(methodId == 4202985802L){
//      List <Argument> args = request.getArgs();
//      Argument arg0 = args.get(0);
//      byte[] serializedNames = arg0.getData();
//      SerializablestringList serializablestringList = new SerializablestringList();
//      serializablestringList.deserialize( serializedNames);
//      List<String> names = serializablestringList.getstringList();
//      Response response = new Response();
//      listTestImpl.addNames(names);
//      response.setStatusCode((byte) 0);
//      response.setData(new byte[]{0});
//      response.setLength(0);
//      return response;
//    }
//    if(methodId == 2800820226L){
//      List <Argument> args = request.getArgs();
//      SerializablestringList serializablestringList = new SerializablestringList();
//      Response response = new Response();
//      List<String> stringList = listTestImpl.getNames();
//      byte[] serializedstringList;
//      if(stringList == null){
//        serializedstringList  = new byte[0];
//      }else{
//        serializablestringList.setstringList(stringList);
//        serializedstringList = serializablestringList.serialize();
//      }
//      response.setStatusCode((byte) 0);
//      response.setData(serializedstringList);
//      response.setLength(serializedstringList.length + 1);
//      return response;
//    }
//    if(methodId == 1872129924L){
//      List <Argument> args = request.getArgs();
//      SerializableMessageList serializableMessageList = new SerializableMessageList();
//      Response response = new Response();
//      List<Message> messageList = listTestImpl.getMessages();
//      byte[] serializedMessageList;
//      if(messageList == null){
//        serializedMessageList  = new byte[0];
//      }else{
//        serializableMessageList.setMessageList(messageList);
//        serializedMessageList = serializableMessageList.serialize();
//      }
//      response.setStatusCode((byte) 0);
//      response.setData(serializedMessageList);
//      response.setLength(serializedMessageList.length + 1);
//      return response;
//    }
//    if(methodId == 3626181027L){
//      List <Argument> args = request.getArgs();
//      Argument arg0 = args.get(0);
//      byte[] serializedMessage = arg0.getData();
//      Message message = new Message();
//      message.deserialize(serializedMessage);
//      Response response = new Response();
//      listTestImpl.addMessage(message);
//      response.setStatusCode((byte) 0);
//      response.setData(new byte[]{0});
//      response.setLength(0);
//      return response;
//    }
//    if(methodId == 1619390066L){
//      List <Argument> args = request.getArgs();
//      Argument arg0 = args.get(0);
//      byte[] serializedNumbers = arg0.getData();
//      Serializableuint16List serializableuint16List = new Serializableuint16List();
//      serializableuint16List.deserialize( serializedNumbers);
//      List<Short> numbers = serializableuint16List.getuint16List();
//      Response response = new Response();
//      listTestImpl.addNumbers(numbers);
//      response.setStatusCode((byte) 0);
//      response.setData(new byte[]{0});
//      response.setLength(0);
//      return response;
//    }
//
//    Response response = new Response();
//    response.setStatusCode((byte) 255);
//    response.setData(new byte[]{0});
//    response.setLength(2);
//    if(Config.isVerboseMode){
//      System.out.println("WARN : method id is incorrect");
//    }
//    return response;
//  }
//}
