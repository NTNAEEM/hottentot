/******************************************************************
 * Generated by Hottentot JAVA Generator
 * Date: 
 * Name: 
 * Description:
 *   
 ******************************************************************/

package example.generated;

import ir.ntnaeem.hottentot.runtime.Service;
import java.util.List;

public interface AuthService extends Service {
  List<Token> auth(Credential credential);
  Token test(List<Human> humans);

}
