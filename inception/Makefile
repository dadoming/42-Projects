all:
	docker-compose up -d

clean:
	docker-compose down
	docker-compose down --rmi all

nginx:
	docker-compose build --no-cache nginx
	docker-compose up -d --no-deps nginx

.PHONY: all clean nginx