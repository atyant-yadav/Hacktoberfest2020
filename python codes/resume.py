# This is Coded by Me(Nirmal Patel) from getting help from blogs The link of blog is:
# https://medium.com/@randerson112358/resume-scanner-2c30f5baf92c
import docx2txt
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.metrics.pairwise import cosine_similarity

resume = docx2txt.process("Nirmal_patel.docx")

# Print the resume
print(resume)

# Store the job description into a variable
job_description = docx2txt.process("explore_microdoft.docx")

# Print the job description
print(job_description)

# A list of text
text = [resume, job_description]

cv = CountVectorizer()
count_matrix = cv.fit_transform(text)

# Print the similarity scores
print("\nSimilarity Scores:")
print(cosine_similarity(count_matrix))

# get the match percentage
matchPercentage = cosine_similarity(count_matrix)[0][1] * 100
matchPercentage = round(matchPercentage, 2)  # round to two decimal
print("Your resume matches about " + str(matchPercentage) + "% of the job description.")
