package org.labcrypto.hottentot.runtime.config;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Properties;

public class Config {
  public static String configPath = "";
  public static boolean isVerboseMode = false;
  public static int SERVER_SOCKET_TIME_OUT = 60000;
  public static int CLIENT_SOCKET_TIME_OUT = 60000;
  public static final String USAGE_HELP_STRING = "usage : -v -ssl --server-cert-file path/to/cert/file --server-cert-pass 123456 --config-path /path/to/config/file ";
  public static int threadPoolSize = 5;
  public static boolean isGCEnabledMode = false;
  public static boolean isSslEnabledMode = false;

  public static void setConfigPropertiesFromConfigFile() throws IOException {
    if (!configPath.equals("")) {
      BufferedReader reader = new BufferedReader(new FileReader(configPath));
      String line;
      while ((line = reader.readLine()) != null) {
        String[] splitedLine = line.split("\\=");
        if (splitedLine[0].equals("THREAD_POOL_SIZE")) {
          threadPoolSize = Integer.parseInt(splitedLine[1]);
        }
      }
    }
  }

  public static void setMainArgs(String[] args) {
    int mainArgsCounter = 0;
    while (mainArgsCounter < args.length) {
      Properties props = System.getProperties();
      if (args[mainArgsCounter].equals("--config-path")) {
        configPath = args[mainArgsCounter + 1];
        mainArgsCounter += 2;
      } else if (args[mainArgsCounter].equals("-v")) {
        isVerboseMode = true;
        mainArgsCounter++;
      } else if (args[mainArgsCounter].equals("-gc")) {
        isGCEnabledMode = true;
        mainArgsCounter++;
      }else if(args[mainArgsCounter].equals("-ssl")) {
        isSslEnabledMode = true;
        mainArgsCounter++;
      }else if(args[mainArgsCounter].equals("--client-socket-timeout")) {
        CLIENT_SOCKET_TIME_OUT = Integer.parseInt(args[mainArgsCounter + 1]);
        mainArgsCounter++;
      }else if(args[mainArgsCounter].equals("--server-socket-timeout")) {
        SERVER_SOCKET_TIME_OUT = Integer.parseInt(args[mainArgsCounter + 1]);
        mainArgsCounter++;
      }else if(args[mainArgsCounter].equals("--thread-pool-size")) {
        threadPoolSize = Integer.parseInt(args[mainArgsCounter + 1]);
        mainArgsCounter++;
      }else if(args[mainArgsCounter].equals("-ssl")) {
        isSslEnabledMode = true;
        mainArgsCounter++;
      } else if (args[mainArgsCounter].equals("--server-cert-file")) {
        props.setProperty("javax.net.ssl.keyStore", args[mainArgsCounter + 1]);
        mainArgsCounter += 2;
      } else if (args[mainArgsCounter].equals("--server-cert-pass")) {
        props.setProperty("javax.net.ssl.keyStorePassword", args[mainArgsCounter + 1]);
        mainArgsCounter += 2;
      } else if (args[mainArgsCounter].equals("--client-cert-file")) {
        props.setProperty("javax.net.ssl.trustStore", args[mainArgsCounter + 1]);
        mainArgsCounter += 2;
      } else if (args[mainArgsCounter].equals("--client-cert-pass")) {
        props.setProperty("javax.net.ssl.trustStorePassword", args[mainArgsCounter + 1]);
        mainArgsCounter += 2;
      }else {
        mainArgsCounter++;
      }
    }
  }
}
