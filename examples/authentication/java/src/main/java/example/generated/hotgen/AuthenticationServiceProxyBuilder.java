/******************************************************************
 * Generated by Hottentot JAVA Generator
 * Date: 
 * Name: 
 * Description:
 *   
 ******************************************************************/
package example.generated.hotgen;

public class AuthenticationServiceProxyBuilder {

  public static AuthenticationService create(String host, int port) {
    return new AuthenticationServiceProxy(host,port);
  }

  public static void destroy() {
    //TODO
  }
}