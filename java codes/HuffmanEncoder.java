import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;

public class HuffmanEncoder {
    private HashMap<Character, String> encoder=new HashMap<>();
    private HashMap<String, Character> decoder=new HashMap<>();
    
    private class Node implements Comparable<Node>{
    	char data;
    	int freq;
    	Node left;
    	Node right;
		@Override
		public int compareTo(Node o) {
			return this.freq-o.freq;
		}
    }
	public HuffmanEncoder(String feeder) {
       HashMap<Character, Integer> fmap=new HashMap<>();
       for(int i=0;i<feeder.length();i++){
    	   char ch=feeder.charAt(i);
    	   fmap.put(ch, fmap.containsKey(ch)?fmap.get(ch)+1:1);
       }
       ArrayList<Character> keys=new ArrayList<>(fmap.keySet());
       PriorityQueue<Node> pq=new PriorityQueue<>();
       for(char key:keys){
    	   Node node=new Node();
    	   node.data=key;
    	   node.freq=fmap.get(key);
    	   pq.add(node);
       }
       while(pq.size()>1){
    	   Node one=pq.remove();
    	   Node two=pq.remove();
    	   Node merge=new Node();
    	   merge.freq=one.freq+two.freq;
    	   merge.left=one;
    	   merge.right=two;
    	   pq.add(merge);
       }
       Node root=pq.remove();
       traverse(root,"");
    }
	private void traverse(Node node, String psf) {
		if(node.left==null&&node.right==null){
			encoder.put(node.data, psf);
			decoder.put(psf, node.data);
			return;
		}
        traverse(node.left, psf+"0");
        traverse(node.right, psf+"1");
	}
	public String Encode(String str){
		String code="";
		for(int i=0;i<str.length();i++){
			code+=encoder.get(str.charAt(i));
		}
		return code;
	}
	public String Decode(String str){
      String decode="";
      String prefix="";
      for(int i=0;i<str.length();i++){
    	  prefix+=str.charAt(i);
    	  if(decoder.containsKey(prefix)){
    		  decode+=decoder.get(prefix);
    		  prefix="";
    	  }
      }
      return decode;
	}
}
