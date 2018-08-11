import junit.framework.TestCase;

public class testcode extends TestCase {

    public testcode(String testName) {
        super(testName);
    }


    public void testIsValid() {
        UrlValidator validator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);


        String[] firstUrlPart = {"http://", "ftp://", "ftp:/", "ftp:", "://", ""};
        Boolean[] firstUrlPartValidity = {true, true, false, false, false, true};
        String[] urlDomains = {"google.com", "google.co.uk", "127.0.0.1", "google.haha", ".g.G.g.", "google.io"};
        Boolean[] urlDomainsValidity = {true, true, true, false, false, true};
        String[] urlPorts = {"", ":5000", ":5", "5000000", ":haha" };
        Boolean[] urlPortsValidity = {true ,true, true, false, false};
        String[] urlPaths = {"","/", "/hello", "/hello/", "../hello/"};
        Boolean[] urlPathsValidity = {true, true, true, true, false};
        //Test allow2slash, noFragment
        String[] urlQuerys = {"?haha=hello&answer=question", "?haha=hello", ""};
        Boolean[] urlQuerysValidity = {true, true, true};
        for(int firstPartIndex = 0; firstPartIndex < firstUrlPart.length - 1; firstPartIndex++){
            String firstUrlString = firstUrlPart[firstPartIndex];
            Boolean firstUrlValid = firstUrlPartValidity[firstPartIndex];
            System.out.println("Test Case");
            for(int urlDomainIndex = 0; urlDomainIndex < urlDomains.length - 1; urlDomainIndex++){
                String urlDomainString = urlDomains[urlDomainIndex];
                Boolean urlDomainValid = urlDomainsValidity[urlDomainIndex];
                for(int urlPortIndex = 0; urlPortIndex < urlPorts.length - 1; urlPortIndex++) {
                    String urlPortString = urlPorts[urlPortIndex];
                    Boolean urlPortValid = urlPortsValidity[urlPortIndex];
                    for(int urlPathIndex = 0; urlPathIndex < urlPaths.length - 1; urlPathIndex++) {
                        String urlPathString = urlPaths[urlPathIndex];
                        Boolean urlPathValid = urlPathsValidity[urlPathIndex];
                        for(int urlQueryIndex = 0; urlQueryIndex < urlQuerys.length - 1; urlQueryIndex++) {
                            String urlQueryString = urlQuerys[urlQueryIndex];
                            Boolean urlQueryValid = urlQuerysValidity[urlQueryIndex];
                            Boolean urlValid = firstUrlValid && urlDomainValid && urlPortValid && urlPathValid
                                    && urlQueryValid;

                            if(urlValid){
                                System.out.print("Test Case for valid url: ");
                            }
                            else{
                                System.out.print("Test Case for invalid url: ");
                            }
                            String url = firstUrlString + urlDomainString + urlPortString + urlPathString +
                                    urlQueryString;
                            Boolean urlValidTest = validator.isValid(url);
                            System.out.println(url);
                            //assertTrue(urlValid == urlValidTest);
                            if(urlValid == urlValidTest){
                                System.out.println("Test Case PASSED");
                            }
                            else{
                                System.out.println("Test Case FAILED");
                            }
                        }
                    }
                }
            }


        }

    }





    public static void main(String[] argv) {

        testcode tc = new testcode("url test");

        tc.testIsValid();

    }


}


