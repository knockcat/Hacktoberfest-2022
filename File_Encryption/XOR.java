package com.encryption;

public class XOR {
    static byte[] operateXOR(int key,byte[] data){
        byte[] res=new byte[data.length];
        for(int i=0;i<data.length;i++){
            res[i]=(byte)(data[i]^key);
        }
        return res;
    }
}
