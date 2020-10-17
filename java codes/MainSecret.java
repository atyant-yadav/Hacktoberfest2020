/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package test1;

/**
 *
 * @author andreannovan
 */
public class MainSecret {
    private static String secretSentence = "jdodawnakusjemrtgemeetwqasdatraway";
    public static void main(String[] args){
//        SecretAgent secretAgent = new SecretAgent();
        String[] keyWords = {"name", "play", "us", "amaze", "at", "dada"};
        String a = findSecretPassword(keyWords);
        System.out.println(a);
    }
    
    public static String findSecretWord(String keyWord){
        char [] tempSecretSentence = secretSentence.toCharArray();
        String secretWord = "null";
        int getKeywordLength = keyWord.length();
        String lastTwoLetter = String.valueOf(keyWord.charAt(getKeywordLength-2))+
                String.valueOf(keyWord.charAt(getKeywordLength-1));
        int secretSentenceLength = secretSentence.length();
        int chekerNumber = 0;
        while(chekerNumber<secretSentenceLength){
            if((secretSentenceLength-chekerNumber)<getKeywordLength){
                break;
            }
            String temp = String.valueOf(secretSentence.charAt(chekerNumber))+
                    String.valueOf(secretSentence.charAt(chekerNumber+1));
            if(temp.equals(lastTwoLetter)){
                if((secretSentenceLength-chekerNumber)<getKeywordLength){
                    break;
                }
                secretWord = "";
                for (int i = 0; i < getKeywordLength; i++) {
                    secretWord = secretWord + String.valueOf(tempSecretSentence[chekerNumber+i]);
                }
                break;
            }
            chekerNumber = chekerNumber+1;
        }
        return secretWord;
    }
    
    public static String findSecretPassword(String [] keyWords){
        String secretMessage = "";
        for (int i = 0; i < keyWords.length; i++) {
            String temp = findSecretWord(keyWords[i]);
            if(!temp.equals("null")){
                secretMessage = secretMessage + temp + " ";
            }
        }
        return secretMessage;
    }
}
