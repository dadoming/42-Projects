NGINX_CONTAINER_NAME = nginx_container
MARIADB_CONTAINER_NAME = mariadb_container

all:
	docker-compose -f ./srcs/docker-compose.yml up -d 

build:
	docker-compose -f ./srcs/docker-compose.yml up -d --build

down:
	docker-compose -f ./srcs/docker-compose.yml down

re:
	docker-compose -f ./srcs/docker-compose.yml up -d --build

clean: down
	docker system prune -a

fclean:
	printf "Total clean of all config docker\n"
	docker stop $$(docker ps -qa)
	docker system prune --all --force --volumes
	docker network prune --force
	docker volume prune --force

.PHONY: all build down re clean fclean