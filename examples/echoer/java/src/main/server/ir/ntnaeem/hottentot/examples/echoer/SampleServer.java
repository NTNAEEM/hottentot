/******************************************************************
 * Generated by Hottentot JAVA Generator
 * Date: 
 * Name: 
 * Description:
 *   
 ******************************************************************/
package ir.ntnaeem.hottentot.examples.echoer;

import java.io.IOException;

import org.labcrypto.hottentot.runtime.Service;
import org.labcrypto.hottentot.runtime.ServiceRuntime;


public class SampleServer {
  public static void main(String[] args) throws IOException {
    org.labcrypto.hottentot.runtime.config.Config.setMainArgs(args);
    org.labcrypto.hottentot.runtime.config.Config.setConfigPropertiesFromConfigFile();
    ServiceRuntime serviceRuntime = new ServiceRuntime();
    Service echoService = new EchoImpl();
    serviceRuntime.register("127.0.0.1",8080, echoService);

    serviceRuntime.start();
  }
}



