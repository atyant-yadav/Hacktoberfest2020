from pytube import YouTube

st=YouTube("https://www.youtube.com/watch?v=NHp-vFqujRc")
#print(st.title)

#print(st.streams.all())

down=st.streams.filter(progressive=True,file_extension='mp4').desc().first()
print(down)
down.download()