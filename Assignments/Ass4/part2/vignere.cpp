

#include "vignere.h"

void vignere_encrypt(char data[], char key[])
{
    char dataOverlay[strlen(data)];
    unsigned long keyLength=strlen(key);
    int overlayCount=0;
    
    //convert key to ucase
    for (int i=0; i<keyLength; i++)
    {
        if ((key[i]>='A' && key[i]<='Z') || (key[i]>='a' && key[i]<='z'))
        {
            if (key[i]>='a' && key[i]<='z')
            {
                //convert to ucase
                key[i]-=32;
            }
            
        }
        else
        {
            //key is invalid
            //do something... maybe dance.
        }
    }
    
    //overlay key
    for (int i=0; data[i]!='\0'; i++)
    {
        if ((data[i]>='A' && data[i]<='Z') || (data[i]>='a' && data[i]<='z'))
        {
            //valid char, overlay
            if (overlayCount>keyLength-1)
                overlayCount=0;
            
            dataOverlay[i]=key[overlayCount];
            overlayCount++;
        }
        else
            dataOverlay[i]=' ';
        
    }
    
    //encrypt
    for (int i=0; data[i]!='\0'; i++)
    {
    
        if ((data[i]>='A' && data[i]<='Z') || (data[i]>='a' && data[i]<='z'))
        {
            bool uCase;
            if (data[i]>='a' && data[i]<='z')
            {
                uCase=false;
                data[i]-=31;
                
            }
            else
            {
                uCase=true;
            }
            
            char dataindex, keyindex;
            dataindex=data[i];
            keyindex=dataOverlay[i];
            dataindex-=65;
            keyindex-=65;
            if (uCase)
            {
                data[i]=keytable[dataindex][keyindex];
            }
            else
            {
                data[i]=keytable[dataindex][keyindex] +31;
            }
            
        }
    }
}

void vignere_decrypt(char data[], char key[])
{
    char dataOverlay[strlen(data)];
    unsigned long keyLength=strlen(key);
    int overlayCount=0;
    
    //convert key to ucase
    for (int i=0; i<keyLength; i++)
    {
        if ((key[i]>='A' && key[i]<='Z') || (key[i]>='a' && key[i]<='z'))
        {
            if (key[i]>='a' && key[i]<='z')
            {
                //convert to ucase
                key[i]-=32;
            }
            
        }
        else
        {
            //key is invalid
            //do something... maybe dance.
        }
    }

    
    //overlay key
    for (int i=0; data[i]!='\0'; i++)
    {
        if ((data[i]>='A' && data[i]<='Z') || (data[i]>='a' && data[i]<='z'))
        {
            //valid char, overlay
            if (overlayCount>keyLength-1)
                overlayCount=0;
            
            dataOverlay[i]=key[overlayCount];
            overlayCount++;
        }
        else
            dataOverlay[i]=' ';
        
    }
    
    //decrypt
    for (int i=0; data[i]!='\0'; i++)
    {
        if ((data[i]>='A' && data[i]<='Z') || (data[i]>='a' && data[i]<='z'))
        {
            char dataindex, keyindex;
            dataindex=data[i];
            bool uCase;
            //conv to ucase if lcase
            if (data[i]>='a' && data[i]<='z')
            {
                uCase=false;
                dataindex-=31;
            }
            else
            {
                uCase=true;
            }
            
            keyindex=dataOverlay[i];
            for (int j=0; j<26; j++)
            {
                if (keytable[j][keyindex-65]==dataindex)
                {
                    if (uCase)
                        data[i]=j+65;
                    else
                        data[i]=j+65+31;
                }
            }
            
        }
    }

}