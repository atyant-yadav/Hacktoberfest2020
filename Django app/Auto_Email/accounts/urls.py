from django.urls import path
from . import views
from django.contrib.auth import views as auth_views
app_name = 'accounts'

urlpatterns = [
    path('sign_up/',views.SignUpView.as_view(), name='sign_up'),
    path('login/', auth_views.LoginView.as_view(template_name = 'accounts/login.html'), name='login'),
    path('logout/', auth_views.LogoutView.as_view(), name='logout'),
]
