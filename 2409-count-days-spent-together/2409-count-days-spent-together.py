
class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        alicearrmon = int(arriveAlice[:2])
        alicearrdate = int(arriveAlice[3:5])
        aliceleamon = int(leaveAlice[:2])
        aliceleadate = int(leaveAlice[3:5])

        bobarrmon = int(arriveBob[:2])
        bobarrdate = int(arriveBob[3:5])
        bobleamon = int(leaveBob[:2])
        bobleadate = int(leaveBob[3:5])

        days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

        alice_start = sum(days[:alicearrmon - 1]) + alicearrdate
        alice_end = sum(days[:aliceleamon - 1]) + aliceleadate
        bob_start = sum(days[:bobarrmon - 1]) + bobarrdate
        bob_end = sum(days[:bobleamon - 1]) + bobleadate

        start = max(alice_start, bob_start)
        end = min(alice_end, bob_end)

        return max(0, end - start + 1)