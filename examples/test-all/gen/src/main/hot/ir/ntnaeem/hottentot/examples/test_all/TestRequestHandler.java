/******************************************************************
 * Generated by Hottentot JAVA Generator
 * Date: 
 * Name: 
 * Description:
 *   
 ******************************************************************/
package ir.ntnaeem.hottentot.examples.test_all;

import java.util.List;

import org.labcrypto.hottentot.helper.*;
import org.labcrypto.hottentot.runtime.Argument;
import org.labcrypto.hottentot.runtime.Request;
import org.labcrypto.hottentot.runtime.RequestHandler;
import org.labcrypto.hottentot.runtime.Response;
import org.labcrypto.hottentot.runtime.Service;
import org.labcrypto.hottentot.runtime.config.Config;
import org.labcrypto.hottentot.runtime.exception.TcpClientConnectException;
import org.labcrypto.hottentot.runtime.exception.TcpClientReadException;
import org.labcrypto.hottentot.runtime.exception.TcpClientWriteException;


public class TestRequestHandler extends RequestHandler {
  public TestRequestHandler(Service service) {
    super(service);
  }
  @Override
  public Response handleRequest(Request request) throws TcpClientWriteException, TcpClientReadException, TcpClientConnectException {
    long methodId = request.getMethodId();
    TestService testImpl = (AbstractTestService) service;
    if(methodId == 910863811L){
      List <Argument> args = request.getArgs();
      Argument arg0 = args.get(0);
      byte[] serializedD = arg0.getData();
      byte[] d = PDTDeserializer.getData(serializedD);
      Response response = new Response();
      byte[] result = testImpl.f1(d);
      byte[] serializedResult = PDTSerializer.getData( result );
      response.setStatusCode((byte) 0);
      response.setData(serializedResult);
      response.setLength(serializedResult.length + 1);
      return response;
    }
    if(methodId == 1537205373L){
      List <Argument> args = request.getArgs();
      Argument arg0 = args.get(0);
      byte[] serializedDl = arg0.getData();
      SerializableDataList serializableDataList_1 = new SerializableDataList();
      serializableDataList_1.deserialize( serializedDl);
      List<byte[]> dl = serializableDataList_1.getDataList();
      Argument arg1 = args.get(1);
      byte[] serializedDl2 = arg1.getData();
      SerializableDataList serializableDataList_2 = new SerializableDataList();
      serializableDataList_2.deserialize( serializedDl2);
      List<byte[]> dl2 = serializableDataList_2.getDataList();
      SerializableDataList serializableDataList_3= new SerializableDataList();
      Response response = new Response();
      List<byte[]> dataList = testImpl.f2(dl,dl2);
      byte[] serializedDataList;
      if(dataList == null){
        serializedDataList  = new byte[0];
      }else{
        serializableDataList_3.setDataList(dataList);
        serializedDataList = serializableDataList_3.serialize();
      }
      response.setStatusCode((byte) 0);
      response.setData(serializedDataList);
      response.setLength(serializedDataList.length + 1);
      return response;
    }
    if(methodId == 4124847715L){
      List <Argument> args = request.getArgs();
      Argument arg0 = args.get(0);
      byte[] serializedLs = arg0.getData();
      SerializableStringList serializableStringList_4 = new SerializableStringList();
      serializableStringList_4.deserialize( serializedLs);
      List<String> ls = serializableStringList_4.getStringList();
      Argument arg1 = args.get(1);
      byte[] serializedLs2 = arg1.getData();
      SerializableStringList serializableStringList_5 = new SerializableStringList();
      serializableStringList_5.deserialize( serializedLs2);
      List<String> ls2 = serializableStringList_5.getStringList();
      Argument arg2 = args.get(2);
      byte[] serializedLs3 = arg2.getData();
      SerializableStringList serializableStringList_6 = new SerializableStringList();
      serializableStringList_6.deserialize( serializedLs3);
      List<String> ls3 = serializableStringList_6.getStringList();
      SerializableStringList serializableStringList_7= new SerializableStringList();
      Response response = new Response();
      List<String> stringList = testImpl.f3(ls,ls2,ls3);
      byte[] serializedStringList;
      if(stringList == null){
        serializedStringList  = new byte[0];
      }else{
        serializableStringList_7.setStringList(stringList);
        serializedStringList = serializableStringList_7.serialize();
      }
      response.setStatusCode((byte) 0);
      response.setData(serializedStringList);
      response.setLength(serializedStringList.length + 1);
      return response;
    }

    Response response = new Response();
    response.setStatusCode((byte) 255);
    response.setData(new byte[]{0});
    response.setLength(2);
    if(Config.isVerboseMode){
      System.out.println("WARN : method id is incorrect");
    }
    return response;
  }
}
