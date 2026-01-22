class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        time.sort()
        def calculate(t):
            total = 0
            for i in time:
                total += t//i
                if i > t: 
                    break
            return total >= totalTrips
        l = 1
        r = time[0]*totalTrips
        ans = -1
        while l <= r: 
            mid = (r+l)//2
            if calculate(mid): 
                ans = mid
                r = mid-1
            else: 
                l = mid+1
        return ans
