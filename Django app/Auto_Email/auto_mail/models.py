from django.db import models

# Create your models here.

class Mail(models.Model):
    created_on = models.DateField(auto_now=True)
    subject = models.CharField(max_length = 100)
    message = models.TextField()

    def __str__(self):
        return self.created_on
        