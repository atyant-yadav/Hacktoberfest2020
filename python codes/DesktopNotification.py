import time
from plyer import notification

if __name__ == "__main__":
    while True:
        notification.notify(
            title="Please Drink Water now !!",
            message="Water is required for your body and brain, for increasing productivity water is needed.",
            app_icon="water_glass.ico",
            timeout=10
        )
        time.sleep(60*60)
