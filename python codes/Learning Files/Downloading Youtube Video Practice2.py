from pytube import YouTube

video=YouTube("https://www.youtube.com/watch?v=7Axsi04rzqk")
#print(video.title)

#print(video.streams.all())

download=video.streams.filter(progressive=True, file_extension='mp4').order_by('resolution').desc().first()
#print(download)

download.download()