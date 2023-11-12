class Reader4 {
    int read4(char[] buf4) {return 0;};
}

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char[] buf4);
 */

class Solution extends Reader4 {
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    public int read(char[] buf, int n) {
        char[] tmp = new char[4];
        int ret = read4(tmp);
        int pos = 0;
        while (ret > 0 && pos < n) {
            for (int i = 0; i < ret; ++i) {
                buf[pos++] = tmp[i];
                if (pos >= n) break;
            }
            
            ret = read4(tmp);
        }
        return pos;
    }
}

public class Main {
    public static void main(String[] args) {
        return;
    }
}
