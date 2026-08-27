class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int n=pushed.length;
        int m=popped.length;
        if(n!=m)return false;
        Stack<Integer> pu=new Stack<>();
        int i,j=0;
        for(i=0;i<n;i++){
            pu.push(pushed[i]);
            while(!pu.isEmpty() && pu.peek()==popped[j]){
                pu.pop();
                j++;
            }
        }
        if(pu.isEmpty())return true;
        return false;
        }
}