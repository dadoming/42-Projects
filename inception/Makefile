
all:
	docker-compose -f ./srcs/docker-compose.yml up -d 

build:
	docker-compose -f ./srcs/docker-compose.yml up -d --build

no-cache:
	docker-compose -f ./srcs/docker-compose.yml up -d --build --no-cache

down:
	docker-compose -f ./srcs/docker-compose.yml down

re:
	docker-compose -f ./srcs/docker-compose.yml up -d --build

clean: down
	docker system prune -a

fclean:
	docker stop $$(docker ps -qa)
	docker system prune --all --force --volumes
	docker network prune --force
	docker volume prune --force

logs:
	@echo ">> MariaDB:\n"
	docker logs mariadb
	@echo "\n"
	@echo ">> Nginx:\n"
	docker logs nginx
	docker exec -it nginx cat /var/log/nginx/error.log
	@echo "\n"
	@echo ">> Wordpress:\n"
	docker logs wordpress
	@echo "\n"

.PHONY: all build down re clean fclean logs no-cache