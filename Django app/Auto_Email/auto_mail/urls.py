from django.urls import path
from . import views
app_name = 'auto_mail'

urlpatterns = [
    path('create/',views.MailCreationView.as_view(), name='create'),
    path('list/',views.MailListView.as_view(), name='list'),
    path('mail/<int:pk>/', views.MailDetailView.as_view(), name='detail'),
    path('mail/<int:pk>/post/', views.post, name='post'),
]
