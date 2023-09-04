class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        l = len(s)
        if(len(s) != len(goal)):
            return False
        if(s==goal):
            return True
        s2 = s
        while(True):
            s3 = ""
            s3 = s3 + s2[-1]
            for i in range(0,l-1):
                s3 = s3 + s2[i]
            s2 = s3
            if(s2==s):
                return False
            if(s2==goal):
                return True
        return False
