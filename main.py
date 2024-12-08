import datetime
file = open("Instagram Number History\instagram.csv", "a")

class gatherData:
    def __init__(self):
        self.followers = []
        self.following = []

    def gatherFollowers(self):
        with open("Instagram Number History\\followers_input.txt", "r", encoding="utf-8") as followers_input:
            for line in followers_input:
                temp = line.split("'")
                if len(temp) > 1:
                    self.followers.append(temp[0])
    
    def gatherFollowing(self):
        with open("Instagram Number History\\following_input.txt", "r", encoding="utf-8") as following_input:
            for line in following_input:
                temp = line.split("'")
                if len(temp) > 1:
                    self.following.append(temp[0])
    
    def writeToFile(self):
        file = open("Instagram Number History\instagram.csv", "a")

        file.write(str(datetime.datetime.now()) + " Followers = " + str(len(self.followers)) + " Following = " + str(len(self.following)) + "\n")

        file.write("Followers\n")
        for follower in self.followers:
            file.write(follower + "\n")
        
        file.write("Following\n")
        for follow in self.following:
            file.write(follow + "\n")

        file.write("Follower Only\n")
        for follower in self.followers:
            if follower not in self.following:
                file.write(follower + "\n")

        file.write("Following Only\n")
        for follow in self.following:
            if follow not in self.followers:
                file.write(follow + "\n")
        
        file.close()

class processData:
    def __init__(self):
        self.followers_curr = []
        self.following_curr = []
        self.followers_prev = []
        self.following_prev = []

gather = gatherData()

gather.gatherFollowers()
gather.gatherFollowing()
gather.writeToFile()